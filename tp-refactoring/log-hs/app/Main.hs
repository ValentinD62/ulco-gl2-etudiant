import System.IO

add3 :: Int -> Int 
add3 = (+3)

mul2 :: Int -> Int
mul2 = (*2)

mycompute :: Int -> IO Int
mycompute v0 = do
    putStrLn ("add3 " ++ show v0)
    let v1 = add3 v0
    putStrLn ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2

mycomputeFile :: Int -> IO Int
mycomputeFile v0 = do
    file <- openFile "test.txt" WriteMode
    hPutStrLn file ("add3 " ++ show v0)
    let v1 = add3 v0
    hPutStrLn file ("mul2 " ++ show v1)
    let v2 = mul2 v1
    hClose file
    return v2

mycomputefin :: Int -> (String -> IO()) -> IO Int
mycomputefin v0 choix = do
    choix ("add3 " ++ show v0)
    let v1 = add3 v0
    choix ("mul2 " ++ show v1)
    let v2 = mul2 v1
    return v2



main :: IO ()
main = do
    putStrLn "this is log-hs"

    res <- mycompute 18
    print res

    resFile <- mycomputeFile 18
    print resFile

    res2 <- mycomputefin 18 putStrLn
    print res2

    hF <- openFile "log2.txt" WriteMode
    resFile2 <- mycomputefin 18 (\str -> hPutStrLn hF str)
    hClose hF
    print resFile2
