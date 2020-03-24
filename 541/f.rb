require "set"
if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i

arr = []
(n-1).times do
	arr.push gets.chomp.split(" ").map(&:to_i)
end

adjhash = Hash.new(Array.new)

arr.each do |x|
	a = x[0]
	b = x[1]

	newa = a
	seenaset = Set.new
	while(adjhash[newa].size==2)
		if(not seenaset.include?(adjhash[newa][0]))
			newa = adjhash[newa][0]
		else
			newa = adjhash[newa][1]
		end
		seenaset.add(newa)
	end

	newb = b
	seenbset = Set.new
	while(adjhash[newb].size==2)
		if(not seenbset.include?(adjhash[newb][0]))
			newb = adjhash[newb][0]
		else
			newb = adjhash[newb][1]
		end
		seenbset.add(newb)
	end

	adjhash[newa]+=[newb]
	adjhash[newb]+=[newa]
end

start = 0
adjhash.each do |k,v|
	if v.size==1
		start=k
		break
	end
end

ansarr = []
#p adjhash
#prev = start

seen = []
prev = prevprev = start
n.times do
	ansarr.push start
	prevprev = prev
	prev = start
	start = (adjhash[start]-[prevprev])[0]
end

ansarr.each do |x|
	print x
	print " "
end
puts