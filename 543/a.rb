if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nmk = gets.chomp.split(" ").map(&:to_i)
n = nmk[0]
m = nmk[1]
k = nmk[2]

power = gets.chomp.split(" ").map(&:to_i)
schools = gets.chomp.split(" ").map(&:to_i)
chosen = gets.chomp.split(" ").map(&:to_i)

schoolsarr = []
m.times {schoolsarr.push []}

(0..n-1).each do |i|
	schoolsarr[schools[i]-1].push power[i]
end

(0..m-1).each do |i|
	schoolsarr[i].sort!
end

ans = 0

#p schoolsarr

chosen.each do |z|
	ind = z-1
#	p ind
#	p schools[ind]
	if (power[ind]!=schoolsarr[schools[ind]-1][-1])
		ans+=1
	end
end

puts ans