if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end



s = gets.chomp
len = s.length

if s.each_char.to_a.uniq.count == 1
	puts "Impossible"
	exit
end

if len%2==1
	news = s[0..len/2-1]+s[len/2+1..-1]
	if news.each_char.to_a.uniq.count == 1
		puts "Impossible"
		exit
	end
end
#p "hi"
if len%2==0
	if(s[0..len/2-1] != s[len/2..-1])
		puts 1
		exit
	end
end

(1..len-1).each do |i|
	#break is before i
	news = s[i..-1]+s[0..i-1] 
	if(news==news.reverse && news != s)
		puts 1
		exit
	end
end

puts 2