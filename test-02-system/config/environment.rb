# frozen_string_literal: true

require 'rubygems'
require 'bundler'
Bundler.require(:default)
Bundler.require(Sinatra::Application.environment)

require './app/server'
