if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end


n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i).sort

k = n/2
s = 0

(0..k-1).each do |i|
	s += (arr[i]+arr[n-1-i])**2
end

puts s