n = 6
k = 3

arr = [6,4,3,0,4,3]

def count(arr)
  k = 0
  (0..arr.length-1).each do |i|
    (i..arr.length-1).each do |j|
      ans = 0
      (i..j).each do |z|
        ans = ans^arr[z]
      end
      if ans!=0
        k+=1
      end
    end
  end

  return k
end


p count(arr)
