FROM fedora:latest

WORKDIR /app

RUN dnf groupinstall -y 'Development Tools'
RUN dnf install -y ruby libcurl-devel json-c-devel && gem install bundler

ENTRYPOINT [ "make test" ]

