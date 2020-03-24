nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]

def findfor(x,y,k)
  count = 0
  (1..x).each do |a|
    (1..y).each do |b|
      if (a**2+b**2)%k==0
        count += 1
      end
    end
  end
  return count
end

if n<m
  puts findfor(n,n,m)
  exit
else
  form = findfor(m,m,m)
  nbym = n/m
  nmodm = n%m

  ans = form*(nbym**2)
  ans += 2*nbym*findfor(m,nmodm,m)
  ans += findfor(nmodm,nmodm,m)
end
puts ans
