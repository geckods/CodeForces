if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

n = gets.to_i
str = gets.chomp

len = str.length

def distance(a,b)
	a = a.ord - "A".ord
	b = b.ord - "A".ord
	return [(a-b).abs,(b-a).abs,(26+a-b).abs,(26+b-a).abs].min
end

ans = 1.0/0.0
(0..len-4).each do |start|
	first = str[start]
	second = str[start+1]
	third = str[start+2]
	fourth = str[start+3]
	minians = distance(first,"A")+distance(second,"C")+distance(third,"T")+distance(fourth,"G")

	if(minians<ans)
		ans=minians
	end
end

puts ans