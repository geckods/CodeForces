n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

sumsforward = []
sumsbackward = []

sum = 0
arr.each do |x|
  sum += x
  sumsforward.push sum
end

sum = 0
arr.reverse.each do |x|
  sum += x
  sumsbackward.push sum
end

newarr = sumsforward&sumsbackward

if newarr.empty?
  puts 0
else
#  newarr.sort!
#  newarr.reverse!
  prev = 0
  newarr.each do |x|
    q = sumsforward.index(x)
    w = n-sumsbackward.index(x)-1
    if w<=q
      puts prev
      exit
    end
    prev = x
  end
end
  
