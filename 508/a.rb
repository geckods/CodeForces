nk = gets.split(" ").map(&:to_i)
str = gets.chomp

n = nk[0]
k = nk[1]

hash = Hash.new(0)
str.each_char do |ch|
  hash[ch]+=1
end

if hash.keys.length < k
  puts 0
else
  puts hash.values.min*k
end
