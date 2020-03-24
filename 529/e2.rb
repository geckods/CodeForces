n = gets.to_i
str = gets.chomp

sum = 0
opencount = 0
closecount = 0
flagdone = false
stackat = []

str.each_char.with_index do |ch,i|
  if ch == "("
    opencount += 1
    sum += 1
  else
    closecount += 1
    sum -=1
  end

  stackat.push sum

  if sum < -2
    flagdone = true
    break
  end
end


if (opencount - closecount).abs != 2 or flagdone
  puts 0
  exit
end

if opencount - closecount == -2
  if str[-1] == "("
    puts 0
    exit
  end

  if str[0] == ")"
    puts 1
    exit
  end

  #convert a close to an open
  ans = 0
  str.each_char.with_index do |ch,i|
    if ch == ")" and stackat[i] < -1
      ans += 1
    end
  end
  puts closecount - 1

else

  if str[0] == ")"
    puts 0
    exit
  end

  if str[-1] == "("
    #you have to change the last one
    puts 1
    exit
  end

  #convert an open to a close
  ans = 0
  str.each_char.with_index do |ch,i|
    if ch == "(" and stackat[i] > 1
      ans += 1
    end
  end
  puts ans
end


