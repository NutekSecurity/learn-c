# frozen_string_literal: true

require 'spec_helper'

RSpec.describe Server do
  def app
    Server
  end
  describe 'GET /' do
    it 'works' do
      get '/'
      expect(last_response).to be_ok
    end
  end

  describe 'ifconfig.me' do
    it 'returns ip address' do
      get '/'
      body = last_response.body
      # search for patter in body
      # that looks like an IP address
      # e.g.
      expect(body).to match(/(\d{1,3}\.){3}\d{1,3}/)
    end
  end

  describe 'Apple Music API' do
    it 'contains artist name' do
      get '/'
      body = last_response.body
      expect(body).to match(/Neosb/)
    end

    it 'contains song name' do
      get '/'
      body = last_response.body
      expect(body).to match(/Set and Settings, Vol. 9/)
    end

    it 'contains song artwork' do
      get '/'
      body = last_response.body
      expect(body).to match(/artworkUrl100/)
    end

    it 'contains song preview' do
      get '/'
      body = last_response.body
      expect(body).to match(/previewUrl/)
    end

    it 'contains song id' do
      get '/'
      body = last_response.body
      expect(body).to match(/1658237994/)
    end
  end
end
