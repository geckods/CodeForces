require 'set'

if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nk = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]

hash = Hash.new(0)
last = Hash.new(-1)
str = gets.chomp

breakpoints = Set.new
(0..n-1).each do |i|
	if str[i]!=str[i+1]
		breakpoints.add(i)
	end
end

toskip = Set.new
breakpoints.each do |br|
	(br-k+2..br).each do |x|
		toskip.add(x)
	end
end


(0..n-k).each do |st|
	next if toskip.include?(st)
	char = str[st]
#	thestr = str[st..st+k-1]
#	next if thestr.each_char.to_a.uniq.length>1
	itslast = last[char]
	next if itslast>=st

	hash[char]+=1
	last[char] = st+k-1
end
#p hash
#p toskip
if hash.empty?
	puts 0
else
	puts hash.values.max
end

#for 1 to k starting index, take steps of k