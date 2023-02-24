FROM fedora:latest

WORKDIR /app

RUN dnf groupinstall -y 'Development Tools'
RUN dnf install -y ruby libcurl-devel json-c-devel && gem install bundler

RUN git clone https://github.com/ThrowTheSwitch/Unity.git
COPY . /app
RUN sed -i 's/..\/unity\//Unity\/src\//' test.c && sed -i 's/-I..\/unity/-IUnity\/src/' Makefile && \
    sed -i 's/..\/unity\//Unity\/src\//' Makefile

ENTRYPOINT [ "make", "test" ]

