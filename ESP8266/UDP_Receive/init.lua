s=net.createServer(net.UDP)
s:on("receive",function(s,c) print(c) end)
s:listen(5683)