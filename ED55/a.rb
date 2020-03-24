t = gets.to_i

t.times do
  nxyd = gets.chomp.split(" ").map(&:to_i)
  n = nxyd[0]
  x = nxyd[1]
  y = nxyd[2]
  d = nxyd[3]
  if (x%d==y%d)
    ans = (x-y).abs/d
  else
    if (y%d==1)
      ans = ((x.to_f-1)/d).ceil + ((y.to_f-1)/d).ceil
      if (n%d==1)
        ans = [ans,((n.to_f-x)/d).ceil+((n.to_f-y)/d).ceil].min
      end
    elsif (n%d==y%d)
      ans = ((n.to_f-x)/d).ceil+((n.to_f-y)/d).ceil
    else
      ans = -1
    end
  end

  puts ans
end
      
