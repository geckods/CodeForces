nk = gets.chomp.split(" ").map(&:to_i)
arr = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]


newarr = arr.map{|x| x%k}
tensarr = []
(0..9).each do |z|
  tensarr.push (10**z)%k
end

count = 0

(0..n-1).each do |a|
  (0..n-1).each do |b|
    next if a==b
    blen = arr[b].to_s.length
    
    ans = (((newarr[a]*tensarr[blen]) + newarr[b])%k)==0
    if ans
      count+=1
    end
  end
end

puts count
