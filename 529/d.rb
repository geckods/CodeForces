n = gets.to_i

hash = Hash.new([])
(1..n).each do |x|
  hash[x] += gets.chomp.split(" ").map(&:to_i)
end

arr = []

thefirstpair = hash[1]
if hash[thefirstpair[0]].include?(thefirstpair[1])
  nextone = thefirstpair[0]
  otherone = thefirstpair[1]
else
  nextone = thefirstpair[1]
  otherone = thefirstpair[0]
end

arr.push 1

while nextone != 1
  arr.push nextone
  asdf = nextone
  nextone = otherone
  otherone = (hash[asdf] - [nextone])[0]
end

arr.each do |x|
  print x
  print " "
end

puts
