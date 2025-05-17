summon varAssign = '[Summon] KnightScript menggunakan <Summon> untuk Variable'
say varAssign
say '[Say] KnightScript menggunakan <Say>, untuk <Print>'
say '[Number] <say & summon> bisa di gunakan untuk mendeklarasikan <Integer>/<Int>'
summon iniNumber = 40
say iniNumber

func iniFunction:
    say '[Func] <Func> cara KnightScript mendeklarasikan function, dan di panggil dengan <Call>'
end

call iniFunction

func ifFunc:
    say '[If] mendeklarasikan <if>'
end

summon numb = 3
if numb < 10
    call ifFunc
end


say '[Say] saat ini KnightScript belum bisa melakukan mengidentifikasi Boolean'