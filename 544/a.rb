if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

time1 = gets.chomp.split(":").map(&:to_i)
time2 = gets.chomp.split(":").map(&:to_i)

thetime1 = time1[0]*60+time1[1]
thetime2 = time2[0]*60+time2[1]

ave = (thetime1+thetime2)/2

def pad(i)
	return i.to_s if(i>9)
	return "0"+i.to_s
end

puts pad(ave/60) + ":" + pad(ave%60)