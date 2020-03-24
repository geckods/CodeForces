n = gets.to_i

gs = gets.chomp


origingold = false
inagold = false
if gs[0]=="G"
  inagold=true
  origingold = true
end

newarr = []

count = 1

gs.each_char.with_index do |ch,i|
  next if i==0
  if inagold
    if ch=="S"
      newarr.push count
      count = 1
      inagold = false
    else
      count+=1
    end
  else
    if ch=="G"
      newarr.push count
      count = 1
      inagold = true
    else
      count += 1
    end
  end
end

newarr.push count

def checkifgold(i,origin)
  if origin
    return i%2==0
  else
    return i%2==1
  end
end

maxgold = 0
maxtwogold = 0
prevgold = 0
wasaone = false

#p newarr

newarr.each_with_index do |x,i|

#  puts wasaone
#  puts x
#  puts i
#  puts checkifgold(i,origingold)

  if checkifgold(i,origingold)
    maxgold = x if x>maxgold
    if wasaone
      asd = prevgold+x+1
      maxtwogold = asd if asd>maxtwogold
    end
    prevgold = x
  else
    if x==1
      wasaone = true
    else
      wasaone = false
    end
  end

end

if newarr.length==1
  if origingold
    puts maxgold
  else
    puts 0
  end
  exit
end

if newarr.length==2
  puts maxgold
  exit
end

if newarr.length==3
  if not origingold
    puts maxgold
    exit
  end
end

if newarr.length<5 or (newarr.length==5 and not origingold)
  puts [maxgold+1,maxtwogold-1].max
  exit
end
#puts maxgold
#puts maxtwogold
puts [maxgold+1,maxtwogold].max
