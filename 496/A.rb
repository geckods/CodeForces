t = gets.to_i
stairs = gets.chomp.split(" ").map(&:to_i)

no = 1
arr = []
prev = 0

stairs.each do |x|
  if x<=prev
    no+=1
    arr.push prev
  end

  prev = x
end

arr.push stairs[-1]
puts no
print arr*" "
puts
