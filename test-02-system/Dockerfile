FROM fedora:latest

WORKDIR /app

RUN dnf groupinstall -y 'Development Tools'
RUN dnf install -y ruby ruby-devel libcurl-devel json-c-devel && gem install bundler

RUN git clone https://github.com/ThrowTheSwitch/Unity.git
COPY . /app
RUN sed -i 's/..\/unity\//Unity\/src\//' test.c && sed -i 's/-I..\/unity/-IUnity\/src/' Makefile && \
    sed -i 's/..\/unity\//Unity\/src\//' Makefile

RUN make && make test && bundle install && bundle exec rspec spec

EXPOSE 9292

ENV RACK_ENV=production 

ENTRYPOINT ["bundle", "exec", "rackup", "--host", "0.0.0.0", "config.ru" ]

