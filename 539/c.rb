if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

xorarr=[]
a = 0
(0..n-1).each do |i|
	a = a^arr[i]
	xorarr.push a
end

evenhash = Hash.new(0)
oddhash = Hash.new(0)
xorarr.insert(0,0)

(0..n).each do |i|
	if(i%2)==0
		evenhash[xorarr[i]]+=1
	else
		oddhash[xorarr[i]]+=1
	end
end

#p evenhash
#p oddhash

=begin
p xorarr
p evenhash
p oddhash
=end
ans = 0
evenhash.each do |k,v|
	ans+=(v*(v-1))/2
end

oddhash.each do |k,v|
	ans+=(v*(v-1))/2
end

puts ans