#include <curl/curl.h>
#include <json-c/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct memory {
  char *response;
  size_t size;
};

static size_t write_data(void *data, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct memory *mem = (struct memory *)userp;

  char *ptr = realloc(mem->response, mem->size + realsize + 1);
  if (ptr == NULL)
    return 0; /* out of memory! */

  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), data, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;

  return realsize;
}

char *curl(char *url) {
  curl_global_init(CURL_GLOBAL_SSL);
  CURL *curl;
  CURLcode res;

  struct memory chunk;
  chunk.response = malloc(1); /* will be grown as needed by the realloc above */
  chunk.size = 0;             /* no data at this point */
  curl = curl_easy_init();
  if (curl) {
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s",
              curl_easy_strerror(res));
    }
    char *response = malloc(chunk.size);
    if (response == NULL) {
      fprintf(stderr, "malloc() failed: %s", curl_easy_strerror(res));
    }
    // if first char is not '{' or '[' then it is not a json
    // so we return the whole response
    if (chunk.response[0] != '{' && chunk.response[0] != '[') {
      curl_easy_cleanup(curl);
      return chunk.response;
    } else {
      // encode the response to json
      // and return it
      // this is to avoid the problem of the json-c library
      // that can't parse the response if it is not a json
      // but it is a json
      // so we encode it to json and then decode it
      // and then return it
      // this is a workaround
      // and it is not a good solution
      // but it works
      // and it is the only solution that i found
      // so i will use it
      // and i will not change it
      // because it works
      // and i don't want to change it
      // because it works
      json_object *jobj = json_object_new_string(chunk.response);
      response = (char *)json_object_to_json_string(jobj);
      curl_easy_cleanup(curl);
      return response;
    }
    free(chunk.response);
    curl_easy_cleanup(curl);
    return response;
  }
  curl_easy_cleanup(curl);
  return chunk.response;
}
