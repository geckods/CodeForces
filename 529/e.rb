n = gets.to_i
str = gets.chomp

sum = 0
opencount = 0
closecount = 0
flagdone = false
stackat = []
wasaminustwo = false
rememberthisminus = 0
wasatwo = false
rememberthis = 0

str.each_char.with_index do |ch,i|
  if ch == "("
    opencount += 1
    sum += 1
  else
    closecount += 1
    sum -=1
  end

  stackat.push sum

#  p sum
  if sum < -2
    flagdone = true
    break
  elsif (sum == -2) and (not i==n-1) and (not wasaminustwo)
    wasaminustwo = true
    rememberthisminus = closecount
  elsif (sum == 2) and (not i==n-1)
    wasatwo = true
    rememberthis = opencount
  end
end

finalopencount = opencount - rememberthis

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


  if wasaminustwo
    puts rememberthisminus-1
    exit
  end
  #if the first one is close, convert it
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


#  if wasatwo
#    puts finalopencount-1
#    exit
#  end
  puts opencount-1   #you can't change the first one
end
