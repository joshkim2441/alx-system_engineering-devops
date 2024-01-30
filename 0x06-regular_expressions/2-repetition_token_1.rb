#!/usr/bin/env ruby
# Accepts one argument and passes it to
# a regular expression method

puts ARGV[0].scan(/hb?tn/).join
