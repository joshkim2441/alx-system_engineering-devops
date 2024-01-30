#!/usr/bin/env ruby
# Ouputs the sender phone number or name
# Reciever phone number or name and flags used

puts ARGV[0].scan(/\[from:(.*?)\]\s\[to:(.*?)\]\s\[flags:(.*?)\]/).join(',')
