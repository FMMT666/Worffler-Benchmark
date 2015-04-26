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



for line1 in fin1:lines() do
	for line2 in fin2:lines() do
		io.write( line1 .. line2 .. "\n" )
	end
	fin2:seek( "set", 0 );
end
