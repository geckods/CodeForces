require 'set'
if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nm = gets.chomp.split(" ").map(&:to_i)

n = nm[0]
m = nm[1]

hash = Hash.new(Array.new)

m.times do
	ab = gets.chomp.split(" ").map(&:to_i)
	a = ab[0]
	b = ab[1]

	hash[a]+=[b]
	hash[b]+=[a]
end

myset = Set.new

maxlen = 0
maxk=0
hash.each do |k,v|
	len = v.length
	if(len>maxlen)
		maxlen = len
		maxk=k
	end
end

myset.add(maxk)
nextqueue = Array.new

hash[maxk].each do |newnode|
	puts "#{maxk} #{newnode}"
	myset.add(newnode)
	nextqueue.push newnode
end

arr = []

while(nextqueue.size >0 && myset.size<n)
	nextval = nextqueue.shift
	hash[nextval].each do |possnext|
		next if myset.include?(possnext)
		arr.push [nextval,possnext]
		myset.add(possnext)
		nextqueue.push possnext
	end
end

arr.each do |x|
	puts "#{x[0]} #{x[1]}"
end