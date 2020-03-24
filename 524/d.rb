t = gets.to_i

def f(x)
  return (2**(x+1))-(x+2)
end

nks = []
t.times do
  nks.push gets.chomp.split(" ").map(&:to_i)
end

nks.each do |nk|
  n = nk[0]
  k = nk[1]

  if (n==1 and k==1)
    puts "YES 0"
    next
  end

  max = (4**n-1)/3
  if (k>max)
    puts "NO"
    next
  end


  if (n==2)
    if (k==3)
      puts "NO"
      next
    end
  end

  #binary seach on n to find the value that works

  min = 0
  max = n
  mid = (min+max)/2
  prev = -100
  twoprev = -100
  while true

    if (f(mid)<=k and f(mid+1)>k)
      #ans is mid
      break
    end
    
    if (min== max)
      break
    end

    if(mid==prev || mid==twoprev)
      if(f(mid+1)<=k)
        mid = mid+1
      end
      break
    end

#    puts "#{min} #{max} #{mid} #{k} #{f(mid)}"
    twoprev = prev
    prev =  mid
    if (f(mid)>k)
      max = mid
      mid = (max+min)/2
      #go to the left
    else
      min = mid
      mid = (min+max)/2
      #go to the right
    end
#    puts "#{min} #{max} #{mid} #{k} #{f(mid)}"
    
  end

  puts "YES #{n-mid}"
end
