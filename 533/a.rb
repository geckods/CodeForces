if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
a = gets.chomp.split(" ").map(&:to_i)


sums = [0]*100

(1..100).each do |x|
	a.each do |y|
		sums[x-1] += [(y-x).abs-1,0].max
	end
end

#p sums
puts "#{sums.index(sums.min)+1} #{sums.min}"