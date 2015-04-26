#!/usr/bin/lua

if arg[1] == nil then
  print("filename 1 missing")
  return
end

fin1 = io.open( arg[1], "r" )
if fin1 == nil then
  print("unable to open file 1")
  return
end

if arg[2] == nil then
  print("filename 2 missing")
  return
end

fin2 = io.open( arg[2], "r" )
if fin2 == nil then
  print("unable to open file 2")
  return
end


local word1
local word2

while 1 do

  word1 = fin1:read("*l")
  if word1 == nil then
    break
  end

  while 1 do
    word2 = fin2:read("*l")
    if word2 == nil then
      fin2:seek("set",0)
      break
    end

    io.write( word1 .. word2 .. "\n" )
    
  end
end
