if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

def gcd(a,b)
	return b if(a==0)
	return gcd(b%a,a)
end

=begin
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
=end

n = gets.to_i
a = gets.chomp.split(" ").map(&:to_i)
b = gets.chomp.split(" ").map(&:to_i)

#c = d*a+b
#c needs to have 0s i.e. c = 0
# d*a = c-b = 0-b
# d = -b/a

hash=Hash.new(0)

zerocount=0
totcount=0

(0..n-1).each do |i|
	mya = a[i]
	myb = b[i]

	if(myb==0)
		if(mya==0)
			totcount+=1
		end
		zerocount+=1
		next
	end

	if(mya==0)
		next
	end

	mygcd = gcd(mya,myb)

	mya/=mygcd
	myb/=mygcd


	hash[[mya,myb]]+=1
end

if hash.empty?
	puts zerocount
else
	puts [hash.values.max+totcount,zerocount].max
end
