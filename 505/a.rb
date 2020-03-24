n = gets.to_i
str = gets.chomp

if n==1
  puts "Yes"
  exit
end

if n>26
  puts "Yes"
else
  hash = Hash.new(0)
  str.each_char {|x| hash[x]+=1}

  if hash.values.max==1
    puts "No"
  else
    puts "Yes"
  end
end
