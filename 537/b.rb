#delete as many as you can, then add to everything else
#delete (n-1) or figure out how many (m-del)/k == n-del is how many you can 

#m-del = kn-k*del
#m-kn = del(1-k)
#del = (m-kn)/1-k
#(k*n-m)/(k-1)

if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

nkm = gets.chomp.split(" ").map(&:to_i)
n=nkm[0]
k=nkm[1]
m=nkm[2]

a = gets.chomp.split(" ").map(&:to_i).sort

if(m>=n)
	max = a.max
	max += [m-n+1,k].min
	puts max
else
	a = a[m..-1]
	sum = a.inject(:+)
	num = n-m
	puts sum/num.to_f
end