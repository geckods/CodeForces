n = gets.to_i
a = gets.chomp.split(" ").map(&:to_i).sort
b = gets.chomp.split(" ").map(&:to_i).sort

diff = 0

turn = 1

(2*n).times do

  if a[-1].nil?
    amax = 0
  else
    amax = a[-1]
  end

  if b[-1].nil?
    bmax = 0
  else
    bmax = b[-1]
  end
=begin
  puts turn
  puts amax
  p a
  puts bmax
  p b
  puts
=end
  if turn==1
    if amax>bmax
      diff += amax
      a.pop
    else
      b.pop
    end
  else
    if amax>bmax
      a.pop
    else
      diff -= bmax
      b.pop
    end
  end
  
  turn = 3-turn
  
end

puts diff
