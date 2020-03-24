def is_square(x)
  Math.sqrt(x) % 1 == 0
end

n = gets.to_i

done = false
count = 0
prevn = n

$callsmade = Hash.new(1.0/0.0)

def findans(n,count)
  $callsmade[n] = count if count<$callsmade[n]
  if n==1
    return [1,count]
  end

#  puts "#{n.to_i} #{count}"
  sqrt = Math.sqrt(n)

  ansarr = []

  if sqrt%1==0    
    ansarr += [findans(sqrt,count+1)]
  else
    a = 2
    newn = a*n

    while newn<n**2
      newn = n*a
      newsqrt = Math.sqrt(newn)
      if newsqrt%1==0
        if (not $callsmade[newsqrt] < count+2)
          temp = findans(newsqrt,count+2)
          ansarr += [temp]
        end
      end
      a = a+1
    end
  end

  minn = 0
  mincount = 0

  if ansarr.empty?
    return [n,count]
  end

  ansarr = ansarr.sort_by{|x| [x[0],x[1]]}

#  p ansarr

  minn = ansarr[0][0]
  mincount = ansarr[0][1]

  if minn == n
    return [n,[mincount,count].min]
  end

  return [minn,mincount]
end

ans = findans(n,0)
puts "#{ans[0].to_i} #{ans[1]}"
#  if done
#    puts "#{n.to_i} #{count}"
#    exit
#  end

