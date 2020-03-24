require 'prime'

n = gets.to_i
a = n.prime_division


count = 0
=begin
while true 

  maxpow = 0
  odd = false
#  p a
  a.each do |z|
    maxpow = z[1] if z[1] > maxpow
    odd = true if z[1]%2==1
  end

  if maxpow == 1
    break
  end

  if odd
    count += 1
    a.each_with_index do |pm,i|
#      if pm[1]%2 !=0
        if maxpow%2==0
          a[i][1]= maxpow
        else
          a[i][1] = maxpow+1
        end
#      end
    end
  end

#  p a
#  p odd
#  p maxpow

  count += 1
  
  a.each_with_index do |pm,i|
    a[i][1]/=2
  end
end

#puts count
ans = 1
a.each do |x|
  ans*=x[0]
end
=end
a = n.prime_division
ans = 1
a.each do |x|
  ans*=x[0]
end

maxpow = 0
powers = []
a.each do |z|
  maxpow = z[1] if z[1]>maxpow
  powers.push z[1]
end

if powers.uniq.length>1 and (Math.log(maxpow)/Math.log(2))%1==0
  count += 1
end

while maxpow>1
  if maxpow%2 == 0
    maxpow/=2
    count += 1
  else
    maxpow = 2**(Math.log(maxpow)/Math.log(2)).ceil
    count += 1
  end
end
puts "#{ans} #{count}"
