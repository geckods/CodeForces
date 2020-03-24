nm = gets.chomp.split(" ").map(&:to_i)
n = nm[0]
m = nm[1]

arr = []

n.times do
  arr.push gets.chomp.split("").map{|z| z=="#"}
end

def nicep arr
  arr.each do |x|
    p x
  end
end

newarr = []

n.times do
  newarr.push [0]*m
end

(0..n-1).each do |i|
  (0..m-1).each do |j|
    if i==0 or j==0 or i==n-1 or j==m-1
      newarr[i][j] = 1
    end

    if arr[i][j] == false
      (0..2).each do |q|
        (0..2).each do |w|
          firstindex = i+q-1
          secondindex = j+w-1
          next if (q==1 and w==1) or (firstindex<0 or firstindex>(n-1) or secondindex<0 or secondindex>(m-1))
          newarr[firstindex][secondindex] = 1 #cannot be a center
        end
      end
    end
  end
end

#nicep newarr


(0..n-1).each do |i|
  (0..m-1).each do |j|
    
    if arr[i][j] == true
      canput = false

      (0..2).each do |q|
        (0..2).each do |w|
          firstindex = i+q-1
          secondindex = j+w-1
          next if (q==1 and w==1) or (firstindex<0 or firstindex>(n-1) or secondindex<0 or secondindex>(m-1))

=begin
          if (firstindex==1 and secondindex==1)
            puts "HI"
          end
=end
          if newarr[firstindex][secondindex] == 0 
            canput = true
            break
          end
        end
        break if canput
      end
      
#      puts "#{canput} #{i} #{j}"

      if not canput
        puts "NO"
        exit
      end
    end
  end
end

puts "YES"
