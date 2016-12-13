#! /usr/bin/ruby

require 'thor'

class SayHi < Thor
  desc "hi NAME", "say hello to NAME"

  def hi(name)
    puts "Hi #{name}!"
  end
end

class FileOp < Thor
  desc 'output FILE_NAME', 'print out the contents of FILE_NAME'
  option :stderr, :type => :boolean

  def output(file_name)
    #options[:stderr] is either true or false depending
    #on whether or not --stderr was passed
    contents = File.read(file_name)
    if options[:stderr]
      $stderr.puts contents
    else
      $stdout.puts contents 
    end
  end
end

FileOp.start(ARGV)
