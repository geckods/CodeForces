nmq = gets.chomp.split(" ").map(&:to_i)
n = nmq[0]
m = nmq[1]
q = nmq[2]
str = gets.chomp
min = gets.chomp

qarr = []
q.times {qarr.push gets.chomp.split(" ").map(&:to_i)}

def count_em(string, substring)
 # count = 0
  ans = []
  biglen = string.length
  smallen = substring.length
  lookfor = substring[0]
  index= 0
  flag = 0
  (0..biglen-smallen+1).each do |i|
    next if i<index
    if string[i] == lookfor
      flag = 0
      isit = true
      (1..smallen-1).each do |j|
        char = substring[j]
        if flag==0 and char==lookfor
          index = i+j
          flag = 1
        end
        if string[i+j] != char
          isit = false
          break
        end
      end
     
      if isit
        ans.push i
      end
    end
  end
  return ans  
end


arr = count_em(str,min)
len = min.length

#p arr
newarr = []
sum = 0
n.times do |i|
  sum += 1 if arr.include?(i)
  newarr.push sum
end
#p arr
#p newarr

sum = 0 
qarr.each do |qu|
  s = qu[0]-1
  e = qu[1]-1
  #puts e-m+1
  #puts s
  flag = false
  if s == 0
    x = 0
    flag = true
  else
    x = s-1
  end

  if e-m+1<0 or e-m+1<(s-1)
    puts 0
    next
  end
  if flag
    puts newarr[e-m+1]
  else
    puts newarr[e-m+1]-newarr[x]
  end
  #puts
#  puts arr.count{|x| x>=s and x<=e-len+1}
end
