if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

require 'set'

nm = gets.chomp.split(" ").map(&:to_i)
hash = Hash.new([])
n = nm[0]
m = nm[1]
m.times do
	asd = gets.chomp.split(" ").map(&:to_i)
	hash[asd[0]]+=[asd[1]]
	hash[asd[1]]+=[asd[0]]
end

seen = Set.new
seen.add(1)

neighbors = Set.new
neighborarr = []
curr = 1

ans = "1 "
#p hash

while seen.size < n
	hash[curr].each do |ne|
		hash[ne].delete(curr)
		next if seen.include?(ne) or neighbors.include?(ne)
		neighbors.add(ne)
		neighborarr.push ne
	end

	neighborarr.sort!
	curr = neighborarr.shift
	neighbors.delete(curr)
	ans+="#{curr.to_i} "
	seen.add(curr)
end

puts ans