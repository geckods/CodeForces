if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end	

n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

arr.sort!
ans1 = arr.max
ans2 = 0
arr.reverse.each do |x|
	if (ans1%x)!=0
		ans2 = x
		break
	end
end

puts ans1

if ans2==0
	max = 0
	arr.uniq.each do |x|
		max = x if (x>max and arr.count(x)==2)
	end
	ans2=max
end
puts ans2