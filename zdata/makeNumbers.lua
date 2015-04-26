#!/usr/bin/lua

if arg[1] == nil then
  arg[1] = 1000
end

for i=0,arg[1]-1 do
  io.write( i, "\n" )
end
