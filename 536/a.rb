if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
arr = []
n.times do
	arr.push gets.chomp.split("")
end

ans = 0
(1..n-2).each do |a|
	(1..n-2).each do |b|
		if arr[a][b]=="X" and arr[a-1][b-1]=="X" and arr[a+1][b-1]=="X" and arr[a-1][b+1]=="X" and arr[a+1][b+1]=="X"
			ans += 1
		end
	end
end

puts ans		