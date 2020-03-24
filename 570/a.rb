if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

a = gets.chomp.to_i

def interesting(a)
	if(a.to_s.each_char.to_a.map(&:to_i).inject(:+)%4==0)
		return true
	else
		return false
	end
end

while(!interesting(a))
	a+=1
end

puts a