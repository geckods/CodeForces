require 'set'
if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]

stud = gets.chomp.split(" ").map(&:to_i).reverse

allowpassarr = []
n.times do
	allowpassarr.push Set.new
end

targetset = Set.new

nastya = stud[0]

m.times do
	ab = gets.chomp.split(" ").map(&:to_i)
	# b can get in front of a(while reversing)
	a = ab[0]
	b = ab[1]

	if(b==nastya)
		targetset.add(a)
	end

	allowpassarr[a-1].add(b)
end


i=1
count=0

#p allowpassarr
#p targetset

while(!targetset.empty? && i<n)
	nextguy = stud[i]
	if targetset.include?(nextguy)
		count+=1
	else
		targetset-=allowpassarr[nextguy-1]
	end
	i+=1
end

puts count