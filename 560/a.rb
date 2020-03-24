if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nxy = gets.chomp.split(" ").map(&:to_i)
n = nxy[0]
x = nxy[1]
y = nxy[2]

s = gets.chomp

ans=0
(0..x-1).each do |i|
#	p i
#	p s[s.length-i-1]
	if(i==y)
		if(s[s.length-i-1]=='0')
			ans+=1
		end
	else
#		p i
		if(s[s.length-i-1]=='1')
			ans+=1
		end
	end
end

puts ans
