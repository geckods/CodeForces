if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end


str = gets.chomp
rev = str.reverse
len = str.length

firstopen = str.index("[")
if firstopen.nil?
	puts -1
	exit
end

firstcolon = str[firstopen..-1].index(":")+firstopen

temp = rev.index("]")
if temp.nil?
	puts -1
	exit
end
lastclose = len-temp-1
lastcolon = len-1-(temp+rev[temp..-1].index(":"))

if lastclose<firstopen || lastcolon<=firstcolon || lastcolon.nil? || firstcolon.nil?
	puts -1
	exit
end

numberofcolons = str[firstcolon..lastcolon].count("|")

puts numberofcolons+4