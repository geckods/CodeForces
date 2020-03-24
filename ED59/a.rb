if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

t = gets.to_i
t.times do
	n = gets.to_i
	num = gets.to_s
	if n>2 or num[1]>num[0]
		puts "YES"
		puts 2
		puts num[0]+" "+num[1..-1]
	else
		puts "NO"
	end
end