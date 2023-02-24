# frozen_string_literal: true

require 'sinatra/base'
require 'ffi'
require 'json'

# Define the FFI interface to the curl() function in the shared library
module CurlLib
  extend FFI::Library
  ffi_lib './curl'
  attach_function :curl, [:string], :string # [] is for arguments, :string is for return type
end

# invoke curl() function from curl.so
# send the result to the view
class Server < Sinatra::Base
  get '/' do
    # pass @curl to the view
    myip = CurlLib.curl 'ifconfig.me'
    @myip = myip.chop # remove trailing '%' from ifconfig.me response
    @title = 'Learn C'
    song = CurlLib.curl 'https://itunes.apple.com/lookup?id=1658237994'
    song = song.strip
    @song_pretty = JSON.pretty_generate(JSON.parse(song))
    song = JSON.parse(song)
    @song_preview = song['results'][0]['previewUrl']
    @song_name = song['results'][0]['trackName']
    @song_artist = song['results'][0]['artistName']
    @song_artwork = song['results'][0]['artworkUrl100']
    @song_url = song['results'][0]['trackViewUrl']
    # pass data to the view
    erb :index,
        locals: {
          curl: @myip,
          title: 'Learn C',
          song_json: @song_pretty,
          song_preview: @song_preview,
          song_name: @song_name,
          song_artist: @song_artist,
          song_artwork: @song_artwork,
          song_url: @song_url
        }, layout: :layout
  end
end
