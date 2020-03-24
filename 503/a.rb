nhabk = gets.chomp.split(" ").map(&:to_i)
n = nhabk[0]
h = nhabk[1]
a = nhabk[2]
b = nhabk[3]
k = nhabk[4]

arr = []
k.times {arr.push gets.chomp.split(" ").map(&:to_i)}

arr.each do |z|
  ta = z[0]
  fa = z[1]
  tb = z[2]
  fb = z[3]

  if ta == tb
    puts (fa-fb).abs
    next
  end

  ans = 0
  floor = fa

  if fa<a
    floor = a
    ans += a-fa
  elsif fa>b
    floor = b
    ans += fa-b
  end


  ans += (tb-ta).abs
  ans += (floor-fb).abs
  
  puts ans
end
