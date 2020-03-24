if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i).sort
sum = arr.inject(:+)
m = gets.to_i
qarr = gets.chomp.split(" ").map(&:to_i)

qarr.each do |q|
	puts sum-arr[-q]
end