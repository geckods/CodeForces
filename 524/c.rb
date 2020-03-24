t = gets.to_i


def colorsin(a,b,n,m)

  squares = (n-a+1)*(m-b+1)
  if (a+b)%2 == 0 #bottom left square is white (more whites)
    black = squares/2
    white = squares-black
  else
    white = squares/2
    black = squares-white
  end

  return [white,black]
end


t.times do
  nm = gets.chomp.split(" ").map(&:to_i)
  rec1 = gets.chomp.split(" ").map(&:to_i)
  rec2 = gets.chomp.split(" ").map(&:to_i)

  n = nm[0]
  m = nm[1]

  x1 = rec1[0]
  y1 = rec1[1]
  x2 = rec1[2]
  y2 = rec1[3]

  x3 = rec2[0]
  y3 = rec2[1]
  x4 = rec2[2]
  y4 = rec2[3]

  squares = n*m
  blacks = (squares)/2
  whites = squares-blacks


  overlap = true
  if (x3>x2 || x4<x1 || y3>y2 || y4<y1)
    overlap = false
  end


  if overlap
    if (x3<=x1)
      x5 = x1
      if (x4<=x2)
        x6 = x4
      else
        x6 = x2
      end
    else
      x5 = x3
      if (x4<=x2)
        x6 = x4
      else
        x6 = x2
      end
    end

    if (y3<=y1)
      y5 = y1
      if (y4<=y2)
        y6 = y4
      else
        y6 = y2
      end
    else
      y5 = y3
      if (y4<=y2)
        y6 = y4
      else
        y6 = y2
      end
    end
  end

  #do for white paint
  colorone = colorsin(x1,y1,x2,y2)
  whites += colorone[1]
  blacks -= colorone[1]
  
  #do for black paint
   
  colortwo = colorsin(x3,y3,x4,y4)
  blacks += colortwo[0]
  whites -= colortwo[0]

  if overlap
    colorthree = colorsin(x5,y5,x6,y6)
    blacks += colorthree[1]
    whites -= colorthree[1]
  end

  puts "#{whites} #{blacks}"
end
