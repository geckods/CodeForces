n = gets.to_f
x = Math.log(n,2)

count = 0
expon = 0
curr = 2**expon


minicount = 0

while (count < n-2)
  print "#{curr} "
  count += 1
  minicount += 1
  if minicount == (n/(curr*2)).round(0)
    minicount = 0
    expon += 1
    curr = 2**expon
  end
end  

thisthing = 2**((x.floor)-1)
if n==1
  puts 1
  exit
end
print "#{thisthing} "
puts "#{(n.to_i/thisthing)*thisthing}"





=begin
(0..x-3).each do |expon|
  curr = 2**expon
  print "#{curr} "*((n/(curr*2)).ceil)
  count += (n/(curr*2)).ceil
end

expon = x-2
=end

=begin
division = n/(curr*2)

while (count+division<n-1)

  print "#{curr} "*(division.ceil)
  count += division.ceil
  expon+=1
  curr = 2**expon
  division = n/(curr*2)
end

max = (n.to_i/curr)*curr
currcopy= curr.dup

while (curr<(max-currcopy))
  print "#{currcopy} "
  curr += currcopy
end

last = curr + currcopy
puts last
=end
